[@bs.config {jsx: 2}];

open Jest;
open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("DocumentTitleJsx2", () => {
  beforeEach(() => DocumentTitle.unsetTitle());

  test("should render nothing if no children", () =>
    <DocumentTitleJsx2 title="Some Title" />
    |> Enzyme.shallow
    |> Enzyme.Renderer.html
    |> expect
    |> toMatchSnapshot
  );

  test("should render childen if provided", () =>
    <DocumentTitleJsx2 title="Some Title">
      <div> "Some Children"->ReasonReact.string </div>
    </DocumentTitleJsx2>
    |> Enzyme.shallow
    |> Enzyme.Renderer.html
    |> expect
    |> toMatchSnapshot
  );

  test("mount should set document title", () => {
    <DocumentTitleJsx2 title="Some Title" /> |> Enzyme.shallow |> ignore;
    expect(DocumentTitle.getTitle()) |> toBe("Some Title");
  });

  test("unmount should set empty document title", () => {
    let wrapper = <DocumentTitleJsx2 title="Some Title" /> |> Enzyme.shallow;

    wrapper |> Enzyme.Renderer.unmount |> ignore;
    expect(DocumentTitle.getTitle()) |> toBe("");
  });
});

describe("DocumentTitleJsx2.handleDidUpdate", () => {
  beforeEach(() => DocumentTitle.unsetTitle());

  test("should set document title if has been changed", () => {
    DocumentTitle.setTitle("Some Title");
    let newTitle = "Another Title";

    DocumentTitleJsx2.handleDidUpdate(newTitle);
    expect(DocumentTitle.getTitle()) |> toBe(newTitle);
  });

  test("should return unit", () => {
    DocumentTitle.setTitle("Some Title");
    let newTitle = "Another Title";

    let result = DocumentTitleJsx2.handleDidUpdate(newTitle);
    expect(result) |> toBe();
  });
});