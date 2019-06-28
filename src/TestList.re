// Utils.requireCSS("./CharacterList.css");

// module CharacterList = [%graphql
//   {|
//       query CharacterList {
//         getCharacters(sortDirection: ASC) {
//           id
//           name
//           playedBy
//           culture
//           allegiances {
//             name
//           }
//           isAlive
//       }
//     }
//   |}
// ];

// module CharacterListQuery = ReasonApolloHooks.Query.Make(CharacterList);

// [@react.component]
// let make = () => {
//   let query = CharacterList.make();
//   let variables = query##variables;

//   let (simple, _full) = CharacterListQuery.use(~variables,());

//   <div className="CharacterList">
//     <h2> {"All Characters" |> React.string} </h2>
//     {switch (simple) {
//      | Loading => <div> {React.string("Loading...")} </div>
//      | NoData => <div> {React.string("No Data...")} </div>
//      | Error(error) => <div> {React.string(error##message)} </div>
//      | Data(response) =>
//        let characters = response##getCharacters;
//        Js.log(characters);
//        <div> {React.string("Loading...")} </div>
//       //  <ul>
//       //    {response##getCharacters
//       //     ->Belt.Array.map(character =>
//       //         <li key={character##id}> {React.string(character##name)} </li>
//       //       )
//       //     ->React.array}
//       //  </ul>;
//      }}
//   </div>;
// };