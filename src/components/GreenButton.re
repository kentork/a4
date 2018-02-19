open Styled;

let button = styled##button([|"\n  background: green;\n"|]);

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=button,
    ~props=Js.Obj.empty(),
    children
  );