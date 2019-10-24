[@bs.val] external document: Dom.document = "document";
[@bs.set] external setTitleDom: (Dom.document, string) => unit = "title";
[@bs.get] external getTitleDom: Dom.document => string = "title";

let getTitle = () => getTitleDom(document);
let setTitle = setTitleDom(document);
let unsetTitle = () => setTitle("");

let useTitle = (title: string): unit =>
  React.useEffect1(
    () => {
      setTitle(title);
      Some(unsetTitle);
    },
    [|title|],
  );

[@react.component]
let make = (~title: string, ~children=?) => {
  useTitle(title);

  switch (children) {
  | Some(childrenCore) => <> childrenCore </>
  | None => React.null
  };
};