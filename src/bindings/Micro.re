type handleResult;

[@bs.module]
external serve : ((Http.req, Http.res) => Http.content) => Http.server =
  "micro";

[@bs.module] external matchRoute : (Http.req, string) => bool = "micro-route/match";