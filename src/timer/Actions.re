let component = ReasonReact.statelessComponent("Actions");

let actionEle = (index, (title, handler)) =>
  <div className="tile" key=("action-" ++ string_of_int(index))>
    <a className="button is-fullwidth is-medium" onClick=handler>
      (title |> ReasonReact.string)
    </a>
  </div>;

let make = (~setWork, ~setShortBreak, ~setLongBreak, _children) => {
  let actions = [|
    ("Work", setWork),
    ("Short Break", setShortBreak),
    ("Long Break", setLongBreak),
  |];

  {
    ...component,
    render: _self =>
      <div className="tile">
        (actions |> Array.mapi(actionEle) |> ReasonReact.array)
      </div>,
  };
};