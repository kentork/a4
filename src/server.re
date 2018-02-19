open Maybe;

let port =
  Js.Dict.get(Node.Process.process##env, "PORT")
  >>= (p => Some(Js.Float.fromString(p)))
  |> (
    fun
    | Some(p) when Js.Float.isNaN(p) => 3000
    | Some(p) => Js.Math.floor(p)
    | None => 3000
  );

let dev =
  Js.Dict.get(Node.Process.process##env, "NODE_ENV")
  |> (
    fun
    | Some(e) => Js.Boolean.to_js_boolean(e !== "production")
    | None => Js.false_
  );

let app = Next.next({"dir": "./src", "dev": dev});

let handle = Next.getRequestHandler(app);

let server =
  Micro.serve((req, res) => {
    let parsedUrl = Url.parse(req##url, Js.true_);
    let query = parsedUrl##query;
    if (Micro.matchRoute(req, "/a")) {
      Next.render(app, req, res, "/b", query);
    } else if (Micro.matchRoute(req, "/b")) {
      Next.render(app, req, res, "/a", query);
    } else {
      handle(req, res, parsedUrl);
    };
  });

Next.prepare(app)
|> Js.Promise.then_(() =>
     Http.listen(
       server,
       port,
       err => {
         if (! Js.Nullable.test(err)) {
           Js.log("js error has occoured !");
         };
         Js.log("> Ready on http://localhost:" ++ string_of_int(port));
       }
     )
   );