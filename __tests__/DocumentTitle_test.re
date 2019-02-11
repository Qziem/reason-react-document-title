open Jest;
open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("DocumentTitle", () => {
  beforeEach(() => DocumentTitle.unsetTitle());

  test("should render nothing if no children", () =>
    <DocumentTitle title="Some Title" />
    |> Enzyme.shallow
    |> Enzyme.Renderer.html
    |> expect
    |> toMatchSnapshot
  );

  test("should render childen if provided", () =>
    <DocumentTitle title="Some Title">
      <div> "Some Children"->ReasonReact.string </div>
    </DocumentTitle>
    |> Enzyme.shallow
    |> Enzyme.Renderer.html
    |> expect
    |> toMatchSnapshot
  );

  test("mount should set document title", () => {
    <DocumentTitle title="Some Title" /> |> Enzyme.shallow |> ignore;
    expect(DocumentTitle.getTitle()) |> toBe("Some Title");
  });

  test("unmount should set empty document title", () => {
    let wrapper = <DocumentTitle title="Some Title" /> |> Enzyme.shallow;

    wrapper |> Enzyme.Renderer.unmount |> ignore;
    expect(DocumentTitle.getTitle()) |> toBe("");
  });
});

describe("DocumentTitle.handleDidUpdate", () => {
  beforeEach(() => DocumentTitle.unsetTitle());

  test("should set document title if has been changed", () => {
    DocumentTitle.setTitle("Some Title");
    let newTitle = "Another Title";

    DocumentTitle.handleDidUpdate(newTitle);
    expect(DocumentTitle.getTitle()) |> toBe(newTitle);
  });

  test("should return unit", () => {
    DocumentTitle.setTitle("Some Title");
    let newTitle = "Another Title";

    let result = DocumentTitle.handleDidUpdate(newTitle);
    expect(result) |> toBe();
  });
});