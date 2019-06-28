module CharacterList = [%graphql
  {|
  query pokemons($first: Int!) {
    pokemons(first: $first) {
      name
    }
  }
  |}
];

module CharacterListQuery = ReasonApolloHooks.Query.Make(CharacterList);

/* Flattens our pokemon list from [{name: "bob"}] -> ["bob"] */
let pokemonList = pokemons =>
  Array.map(
    pokemon =>
      switch (pokemon) {
      | Some(pokemon) =>
        switch (pokemon##name) {
        | Some(name) => name
        | None => ""
        }
      | None => ""
      },
    pokemons,
  );
[@react.component]
let make = () => {
  /* Both variant and records available */
  let query = CharacterList.make(~first=5, ());
  let variables = query##variables;

  let (simple, _full) = CharacterListQuery.use(~variables, ());

  <div>
    {switch (simple) {
     | Loading => <p> {React.string("Loading...")} </p>
     | Data(data) =>
       Js.log(data);
       switch (data##pokemons) {
       | Some(pokemons) =>
         let pokemons = pokemons->pokemonList;
         Js.log(pokemons);
         React.string("Check Console!");
        <ul>
          {pokemons
           ->Belt.Array.map(name =>
               <li> {React.string(name)} </li>
             )
           ->React.array}
        </ul>;
       | None => React.null
       };
     | NoData
     | Error(_) => <p> {React.string("Get off my lawn!")} </p>
     }}
  </div>;
};