/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
// let httpLink =
//   ApolloLinks.createHttpLink(~uri="http://localhost:4000", ());
let httpLink =
  ApolloLinks.createHttpLink(~uri="https://graphql-pokemon.now.sh", ());

let client =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

ReactDOMRe.renderToElementWithId(
  <ReasonApolloHooks.ApolloProvider client> <TestPokemonList /> </ReasonApolloHooks.ApolloProvider>,
  "root",
);