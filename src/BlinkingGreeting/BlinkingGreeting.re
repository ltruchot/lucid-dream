type inferredConcept = {
  concept: string,
  value: string
};

type customError =  { 
  code: int,  
  msg: string,  
  data: Js.nullable(array(string))
};

type concept = {
  key: string,
  is: array(string),
  contains: array(array(string))
}

type processError = {
  input: Js.nullable(string),
  config: Js.nullable(array(concept)),
  errors: array(customError)
};

type inferred = {
  input: string,
  config: array(concept),
  sanitized: string,
  words: array(string),
  solution: array(string),
  understood: array(inferredConcept),
};



let sentences: array(concept) = [|
  {
    key: "sentence",
    is:[||],
    contains: [|
      [|"*subject", "*intransitiveVerb"|],
      [|"*article", "*subject", "*intransitiveVerb"|],
      [|"*subject", "*linkingVerb", "*adjective"|],
      [|"*article", "*subject", "*linkingVerb", "*adjective"|]
    |]
  },
  {
      key: "article",
      is: [|"this", "the", "a"|],
      contains: [||]
  },
  {
    key: "subject",
    is: [|"cat", "sky", "grandma"|],
      contains: [||]
  },
  {
    key: "linkingVerb",
    is: [|"is", "seems", "becomes"|],
      contains: [||]
  },
  {
    key: "intransitiveVerb",
    is: [|"sings", "calms down"|],
      contains: [||]
  },
  {
    key: "adjective",
    is: [|"gray", "threatening"|],
      contains: [||]
  },
|];

[@bs.module "scoped-natural-language-processor"] external process : 
  (array(concept), string) => (Js.nullable(processError), Js.nullable(inferred)) = "process";

Js.log(process(sentences, "the cat is threatening"));

[@react.component]
let make = (~children) => {
  let (show, setShow) = React.useState(() => true);

  // Notice that instead of `useEffect`, we have `useEffect0`. See
  // reasonml.github.io/reason-react/docs/en/components#hooks for more info
  React.useEffect0(() => {
    let id =
      Js.Global.setInterval(
        () => setShow(previousShow => !previousShow),
        1000,
      );

    Some(() => Js.Global.clearInterval(id));
  });

  let style =
    if (show) {
      ReactDOMRe.Style.make(~opacity="1", ~transition="opacity 1s", ());
    } else {
      ReactDOMRe.Style.make(~opacity="0", ~transition="opacity 1s", ());
    };

  <div style> children </div>;
};
