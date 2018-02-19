type app;

type option = {
  .
  "dir": string,
  "dev": Js.boolean
};

type handle = (Http.req, Http.res, Url.parced) => Http.content;

[@bs.module] external next : option => app = "next";

[@bs.send] external getRequestHandler : app => handle = "getRequestHandler";

[@bs.send]
external render : (app, Http.req, Http.res, string, Url.query) => Http.content =
  "render";

[@bs.send] external prepare : app => Js.Promise.t(unit) = "prepare";

module Link = {
  [@bs.module "next/link"] external link : ReasonReact.reactClass = "default";
  let make = (~href=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=link,
      ~props=Js.Undefined.({"href": from_opt(href)}),
      children
    );
};