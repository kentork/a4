open Jest;

describe("Component", () => {
  open ExpectJs;

  test("renders", () => {
    let component = ReactTestRenderer.create(
      <GreenButton>(ReasonReact.stringToElement("aaa"))</GreenButton>
    ) |> ReactTestRenderer.toJSON;

    expect(component) |> toMatchSnapshot;
  });
});