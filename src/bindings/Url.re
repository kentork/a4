type query;

type parced = {. "query": query};

[@bs.module "url"] external parse : (string, Js.boolean) => parced = "parse";