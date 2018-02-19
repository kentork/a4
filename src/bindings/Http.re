type req = {. "url": string};

type res;

type server;

type port = int;

type content;

[@bs.send]
external listen :
  (server, port, Js.Nullable.t(Exn.t) => unit) => Js.Promise.t(unit) =
  "listen";