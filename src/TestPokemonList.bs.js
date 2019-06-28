// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Js_json = require("bs-platform/lib/js/js_json.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Query$ReasonApolloHooks = require("reason-apollo-hooks/src/Query.bs.js");

var ppx_printed_query = "query pokemons($first: Int!)  {\npokemons(first: $first)  {\nname  \n}\n\n}\n";

function parse(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "pokemons");
    var tmp;
    if (match$1 !== undefined) {
      var value$1 = Caml_option.valFromOption(match$1);
      var match$2 = Js_json.decodeNull(value$1);
      if (match$2 !== undefined) {
        tmp = undefined;
      } else {
        var match$3 = Js_json.decodeArray(value$1);
        tmp = match$3 !== undefined ? match$3.map((function (value) {
                  var match = Js_json.decodeNull(value);
                  if (match !== undefined) {
                    return undefined;
                  } else {
                    var match$1 = Js_json.decodeObject(value);
                    var tmp;
                    if (match$1 !== undefined) {
                      var match$2 = Js_dict.get(Caml_option.valFromOption(match$1), "name");
                      var tmp$1;
                      if (match$2 !== undefined) {
                        var value$1 = Caml_option.valFromOption(match$2);
                        var match$3 = Js_json.decodeNull(value$1);
                        if (match$3 !== undefined) {
                          tmp$1 = undefined;
                        } else {
                          var match$4 = Js_json.decodeString(value$1);
                          tmp$1 = match$4 !== undefined ? match$4 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$1));
                        }
                      } else {
                        tmp$1 = undefined;
                      }
                      tmp = {
                        name: tmp$1
                      };
                    } else {
                      tmp = Js_exn.raiseError("graphql_ppx: Object is not a value");
                    }
                    return Caml_option.some(tmp);
                  }
                })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$1));
      }
    } else {
      tmp = undefined;
    }
    return {
            pokemons: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make(first, param) {
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[/* tuple */[
                  "first",
                  first
                ]]),
          parse: parse
        };
}

function makeWithVariables(variables) {
  var first = variables.first;
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[/* tuple */[
                  "first",
                  first
                ]]),
          parse: parse
        };
}

function ret_type(f) {
  return /* module */[];
}

var MT_Ret = /* module */[];

var CharacterList = /* module */[
  /* ppx_printed_query */ppx_printed_query,
  /* query */ppx_printed_query,
  /* parse */parse,
  /* make */make,
  /* makeWithVariables */makeWithVariables,
  /* ret_type */ret_type,
  /* MT_Ret */MT_Ret
];

var CharacterListQuery = Query$ReasonApolloHooks.Make([
      ppx_printed_query,
      parse
    ]);

function pokemonList(pokemons) {
  return $$Array.map((function (pokemon) {
                if (pokemon !== undefined) {
                  var match = Caml_option.valFromOption(pokemon).name;
                  if (match !== undefined) {
                    return match;
                  } else {
                    return "";
                  }
                } else {
                  return "";
                }
              }), pokemons);
}

function TestPokemonList(Props) {
  var query = make(5, /* () */0);
  var variables = query.variables;
  var match = Curry._3(CharacterListQuery[/* use */0], Caml_option.some(variables), undefined, /* () */0);
  var simple = match[0];
  var tmp;
  if (typeof simple === "number") {
    tmp = simple === 0 ? React.createElement("p", undefined, "Loading...") : React.createElement("p", undefined, "Get off my lawn!");
  } else if (simple.tag) {
    tmp = React.createElement("p", undefined, "Get off my lawn!");
  } else {
    var data = simple[0];
    console.log(data);
    var match$1 = data.pokemons;
    if (match$1 !== undefined) {
      var pokemons = pokemonList(match$1);
      console.log(pokemons);
      tmp = React.createElement("ul", undefined, Belt_Array.map(pokemons, (function (name) {
                  return React.createElement("li", undefined, name);
                })));
    } else {
      tmp = null;
    }
  }
  return React.createElement("div", undefined, tmp);
}

var make$1 = TestPokemonList;

exports.CharacterList = CharacterList;
exports.CharacterListQuery = CharacterListQuery;
exports.pokemonList = pokemonList;
exports.make = make$1;
/* CharacterListQuery Not a pure module */
