Utils.requireCSS("./CharacterList.css");

module QueryConfig = [%graphql
  {|
      query CharacterList {
  getCharacters(sortDirection: ASC) {
    id
    name
    playedBy
    culture
    allegiances {
      name
    }
    isAlive
  }
}
  |}
];

module CharacterListQuery = ReasonApolloHooks.Query.Make(QueryConfig);

[@react.component]
let make = () => {
  let query = QueryConfig.make(());
  Js.log2("QUERY: ", query);
  let (simple, _full) = CharacterListQuery.use(());

  <div className="CharacterList">
    <h2> {"All Characters" |> React.string} </h2>
      {React.string("Check Console")}

    {switch (simple) {
     | Loading => <div> {React.string("Loading...")} </div>
     | NoData => <div> {React.string("No Data...")} </div>
     | Error(error) => <div> {React.string(error##message)} </div>
     | Data(data) =>
       //  let characters = data##getCharacters;
       //  Js.log(characters);
       Js.log(data);
       React.string("Data should be in console");
     }}

  </div>;
};