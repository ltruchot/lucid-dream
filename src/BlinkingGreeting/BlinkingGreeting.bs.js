'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ScopedNaturalLanguageProcessor = require("scoped-natural-language-processor");

var sentences = /* array */[
  {
    key: "sentence",
    is: /* array */[],
    contains: /* array */[
      /* array */[
        "*subject",
        "*intransitiveVerb"
      ],
      /* array */[
        "*article",
        "*subject",
        "*intransitiveVerb"
      ],
      /* array */[
        "*subject",
        "*linkingVerb",
        "*adjective"
      ],
      /* array */[
        "*article",
        "*subject",
        "*linkingVerb",
        "*adjective"
      ]
    ]
  },
  {
    key: "article",
    is: /* array */[
      "this",
      "the",
      "a"
    ],
    contains: /* array */[]
  },
  {
    key: "subject",
    is: /* array */[
      "cat",
      "sky",
      "grandma"
    ],
    contains: /* array */[]
  },
  {
    key: "linkingVerb",
    is: /* array */[
      "is",
      "seems",
      "becomes"
    ],
    contains: /* array */[]
  },
  {
    key: "intransitiveVerb",
    is: /* array */[
      "sings",
      "calms down"
    ],
    contains: /* array */[]
  },
  {
    key: "adjective",
    is: /* array */[
      "gray",
      "threatening"
    ],
    contains: /* array */[]
  }
];

console.log(ScopedNaturalLanguageProcessor.process(sentences, "the cat is threatening"));

function BlinkingGreeting(Props) {
  var children = Props.children;
  var match = React.useState((function () {
          return true;
        }));
  var setShow = match[1];
  React.useEffect((function () {
          var id = setInterval((function (param) {
                  return Curry._1(setShow, (function (previousShow) {
                                return !previousShow;
                              }));
                }), 1000);
          return (function (param) {
                    clearInterval(id);
                    return /* () */0;
                  });
        }), ([]));
  var style = match[0] ? ({
        opacity: "1",
        transition: "opacity 1s"
      }) : ({
        opacity: "0",
        transition: "opacity 1s"
      });
  return React.createElement("div", {
              style: style
            }, children);
}

var make = BlinkingGreeting;

exports.sentences = sentences;
exports.make = make;
/*  Not a pure module */
