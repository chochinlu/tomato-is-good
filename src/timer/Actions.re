let component = ReasonReact.statelessComponent("Actions");

let actionEle = (index, title) => {
  let iconStyle = "fas fa-" ++ (title == "Start" ? "play" : "stop");

  <div className="tile" key={"action-" ++ string_of_int(index)}>
    <a className="button is-fullwidth is-medium">
      <span className="icon"> <i className=iconStyle /> </span>
      <span> {title |> ReasonReact.string} </span>
    </a>
  </div>;
};

let make = _children => {
  let actions = [|"Start", "Stop"|];
  {
    ...component,
    render: _self =>
      <div className="tile">
        {actions |> Array.mapi(actionEle) |> ReasonReact.array}
      </div>,
  };
};