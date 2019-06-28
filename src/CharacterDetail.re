Utils.requireCSS("./CharacterDetail.css");
module QueryConfig = [%graphql
  {|
      query CharacterDetail($id: ID!) {
    getCharacter(characterId: $id) {
      id
      name
    playedBy
    culture
    titles
    aliases
    born
    died
    }
  }
  |}
];

module CharacterDetailQuery = ReasonApolloHooks.Query.Make(QueryConfig);

[@react.component]
let make = () => {
  let query = QueryConfig.make(~id="29", ());
    Js.log2("DETAIL_QUERY: ", query);

  let variables = query##variables;
  let (simple, _full) = CharacterDetailQuery.use(~variables, ());
  <div className="CharacterDetail">
    {switch (simple) {
     | Loading => <div> {React.string("Loading")} </div>
     | Error(error) => <div> {React.string(error##message)} </div>
     | NoData => React.null
     | Data(data) =>
       switch (data##getCharacter) {
       | None => "No Character Data" |> React.string
       | Some(character) => <p> {React.string(character##name)} </p>
       }
     }}
  </div>;
};