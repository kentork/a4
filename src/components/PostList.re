type action =
  | Click
  | Toggle;

type state = {
  count: int,
  show: bool
};

let component = ReasonReact.reducerComponent("PostList");

let make = _children => {
  ...component,
  initialState: () => {count: 0, show: false},
  reducer: (action, state) =>
    switch action {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    },
  render: self => {
    let message = "Clicked " ++ string_of_int(self.state.count) ++ " times(s)";
    <div className="hiroshi">
      <GreenButton> (ReasonReact.stringToElement("parapa")) </GreenButton>
      <button
        onClick=(_event => self.send(Click))
        onSubmit=(_event => self.send(Toggle))
      />
      (ReasonReact.stringToElement(message))
    </div>;
  }
};