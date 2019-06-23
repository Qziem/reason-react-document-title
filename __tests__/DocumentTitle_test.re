open Jest;
open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("DocumentTitle", () => {
  beforeEach(() => DocumentTitle.unsetTitle());

  test("should render nothing if no children", () =>
    <DocumentTitle title="Some Title" />
    |> Enzyme.mount
    |> Enzyme.Renderer.html
    |> expect
    |> toMatchSnapshot
  );

  test("should render childen if provided", () =>
    <DocumentTitle title="Some Title">
      <div> "Some Children"->ReasonReact.string </div>
    </DocumentTitle>
    |> Enzyme.mount
    |> Enzyme.Renderer.html
    |> expect
    |> toMatchSnapshot
  );

  test("should set document title on mount", () => {
    <DocumentTitle title="Some Title" /> |> Enzyme.mount |> ignore;

    expect(DocumentTitle.getTitle()) |> toBe("Some Title");
  });

  test("should set empty document title on unmount", () => {
    let wrapper = <DocumentTitle title="Some Title" /> |> Enzyme.mount;
    wrapper |> Enzyme.Renderer.unmount |> ignore;

    expect(DocumentTitle.getTitle()) |> toBe("");
  });

  test("change title prop should set new document title", () => {
    let wrapper = <DocumentTitle title="Some Title" /> |> Enzyme.mount;
    wrapper |> Enzyme.Renderer.setJsProps({"title": "New Title"}) |> ignore;

    expect(DocumentTitle.getTitle()) |> toBe("New Title");
  });
});