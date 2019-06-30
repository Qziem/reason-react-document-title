# Reason React Document Title
Provide reason react component for manage document.title

### Installation
```sh
# yarn
yarn add reason-react-document-title

# npm
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
[@react.component]
let make = () => {
  <div>
    <DocumentTitle title="My title" />
    ... some stuff
  </div>
};
```

Or if you like:
```javascript
[@react.component]
let make = () => {
  <DocumentTitle title="My title">
    <div>
      ... some stuff
    </div>
  </DocumentTitle>,
};
```

### Jsx2
Library also provide component for older Jsx2 version. If you must, use it like this:
```javascript
<DocumentTitleJsx2 title="My title" />
```
It also supports children.

### How it works?
Changing title prop will affect on document.title automatically.
When component is unmounted, document.title value will be set to empty string.

If find any problems or have improvement idea, feel free to create issue :)
