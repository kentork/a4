open Jest;

describe("Expect", () => {
  open Expect;

  test("toBe", () =>
    expect(Calc.add(1, 2)) |> toBe(3))

});
