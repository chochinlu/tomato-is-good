let component = ReasonReact.statelessComponent("SettingActions");

let actionEle = (index, title) =>
  <div className="tile" key={"setting-action-" ++ string_of_int(index)}>
    <a className="button is-fullwidth is-normal">
      {title |> ReasonReact.string}
    </a>
  </div>;

let make = _children => {
  let actions = [|"Work", "Short Break", "Long Break"|];

  {
    ...component,
    render: _self =>
      <div className="tile">
        {actions |> Array.mapi(actionEle) |> ReasonReact.array}
      </div>,
  };
};