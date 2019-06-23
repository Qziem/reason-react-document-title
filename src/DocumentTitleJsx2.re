[@bs.config {jsx: 2}];

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

let handleDidUpdate = title =>
  title !== DocumentTitle.getTitle() ? DocumentTitle.setTitle(title) : ();

let make = (~title: string, children) => {
  ...component,
  didMount: _self => DocumentTitle.setTitle(title),
  didUpdate: _oldAndNewSelf => handleDidUpdate(title),
  willUnmount: _self => DocumentTitle.unsetTitle(),
  render: _self => <Fragment> ...children </Fragment>,
};