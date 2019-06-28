module Styles = {
  open Css;

  let coldStart =
    style([fontFamily("'Space Mono', monospace"), fontSize(rem(1.5))]);
};

let str = React.string;

[@react.component]
let make = () => {
  <h1 className=Styles.coldStart>
    "The deployed server is a CodeSandbox.io instance booting from a cold start. Wait ~30 seconds after executing your first query to see results. After that, you should see updates instantly!"
    ->str
  </h1>;
};