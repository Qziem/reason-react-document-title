# Reason React Document Title
Provide reason react component for manage document.title

### Installation
using yarn:
```sh
yarn add reason-react-document-title
```
using npm:
```sh
npm install reason-react-document-title --save
```
Remeber, add to `bsconfig.json`:
```json
{
  "bs-dependencies": ["reason-react-document-title"]
}
```

### Usage
For example:
```javascript
let make = _children => {
  ...component,
  render: _self => 
    <div>
        <DocumentTitle title="My title" />
        ... some stuff
    </div>,
};
```

Or if you like:
```javascript
let make = _children => {
  ...component,
  render: _self => 
    <DocumentTitle title="My title">
        <div>
            ... some stuff
        </div>
    </DocumentTitle>,
};
```

Changing title prop will affect on document.title automatically.

When component is unmounted, document.title value will be set to empty string.

If find any problems or have improvement idea, feel free to create issue :)
