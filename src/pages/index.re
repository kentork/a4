let component = ReasonReact.statelessComponent("Index");

let make = () => {
  ...component,
  render: _self =>
    <ul>
      <li>
        <Next.Link href="/a">
          <a> (ReasonReact.stringToElement("a")) </a>
        </Next.Link>
      </li>
      <li>
        <Next.Link href="/b">
          <a> (ReasonReact.stringToElement("b")) </a>
        </Next.Link>
      </li>
      <li> <PostList /> </li>
    </ul>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make());