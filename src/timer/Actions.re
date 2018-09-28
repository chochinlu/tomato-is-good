let component = ReasonReact.statelessComponent("Actions");

let actionEle = (index, (title, handler)) => {
  let iconStyle = "fas fa-" ++ (title == "Start" ? "play" : "stop");

  <div className="tile" key=("action-" ++ string_of_int(index))>
    <a className="button is-fullwidth is-medium" onClick=handler>
      <span className="icon"> <i className=iconStyle /> </span>
      <span> (title |> ReasonReact.string) </span>
    </a>
  </div>;
};

let make = (~setStart, ~setStop, _children) => {
  let actions = [|("Start", setStart), ("Stop", setStop)|];
  {
    ...component,
    render: _self =>
      <div className="tile">
        (actions |> Array.mapi(actionEle) |> ReasonReact.array)
      </div>,
  };
};