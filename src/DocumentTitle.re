let component = ReasonReact.statelessComponent("DocumentTitle");

[@bs.module "react"]
external fragmentClass: ReasonReact.reactClass = "Fragment";
module Fragment = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=fragmentClass,
      ~props=Js.Obj.empty(),
      children,
    );
};

[@bs.val] external document: Dom.document = "document";
[@bs.set] external setTitleDom: (Dom.document, string) => unit = "title";
[@bs.get] external getTitleDom: Dom.document => string = "title";

let getTitle = () => getTitleDom(document);
let setTitle = setTitleDom(document);
let unsetTitle = () => setTitle("");

let handleDidUpdate = title => title !== getTitle() ? setTitle(title) : ();

let make = (~title: string, children) => {
  ...component,
  didMount: _self => setTitle(title),
  didUpdate: _oldAndNewSelf => handleDidUpdate(title),
  willUnmount: _self => unsetTitle(),
  render: _self => <Fragment> ...children </Fragment>,
};