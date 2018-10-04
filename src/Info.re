let titleEle = title =>
  <span>
    <strong> {"  [ " ++ title ++ " ]" |> ReasonReact.string} </strong>
  </span>;

let component = ReasonReact.statelessComponent("Info");

let make = (~title, _children) => {
  ...component,
  render: _self =>
    <div className="notification">
      <i className="fas fa-info-circle" />
      {title |> titleEle}
    </div>,
};