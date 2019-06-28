Utils.requireCSS("./CharacterList.css");

module QueryConfig = [%graphql
  {|
      query CharacterList {
    getCharacters(sortDirection: ASC) {
      id
      name
    }
  }
  |}
];

module CharacterListQuery = ReasonApolloHooks.Query.Make(QueryConfig);

[@react.component]
let make = () => {
  let query = QueryConfig.make();
  let variables = query##variables;
  Js.log2("QUERY: ", query);
  Js.log2("variables: ", variables);
  // let (simple, _full) = CharacterListQuery.use(~variables, ());
  let (simple, _full) = CharacterListQuery.use(());
  Js.log(simple);

  <div className="CharacterList">

      <h2> {"All Characters" |> React.string} </h2>
      {React.string("Check Console")}
    </div>;
    // {switch (simple) {
    //  | Loading => <div> {React.string("Loading...")} </div>
    //  | NoData => <div> {React.string("No Data...")} </div>
    //  | Error(error) => <div> {React.string(error##message)} </div>
    //  | Data(data) =>
    //    //  let characters = data##getCharacters;
    //    //  Js.log(characters);
    //    Js.log(data);
    //    React.string("Data should be in console");
    //  }}
};