# Reason React Document Title
Provide reason react component for manage document.title

### Usage
For example:
```javascript
let make = (~title: string, _children) => {
  ...component,
  render: _self => 
    <div>
        <DocumentTitle title />
        ... some stuff
    </div>,
};
```

Or if you like:
```javascript
let make = (~title: string, _children) => {
  ...component,
  render: _self => 
    <DocumentTitle title>
        <div>
            ... some stuff
        </div>
    </DocumentTitle>,
};
```

Changing title prop will affect on document.title automatically.
If the component is unmounted, the document.title value will be set to empty string.