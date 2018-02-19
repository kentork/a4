let (>>=) = (monad: option('a), trans: 'a => option('b)) : option('b) =>
  switch monad {
  | Some(value) => trans(value)
  | None => None
  };