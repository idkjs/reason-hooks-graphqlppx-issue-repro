/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(~uri="https://j96vt.sse.codesandbox.io/", ());

let client =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

ReactDOMRe.renderToElementWithId(
  <ReasonApolloHooks.ApolloProvider client>
    <ColdStart />
    <TestList />
    <CharacterDetail />
  </ReasonApolloHooks.ApolloProvider>,
  "root",
);