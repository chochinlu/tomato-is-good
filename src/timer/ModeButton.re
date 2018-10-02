let component = ReasonReact.statelessComponent("ModeButton");

let make = (~label, ~onClick, ~selected, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <a
        className={
          "button is-fullwidth is-normal "
          ++ (selected ? "is-info is-selected" : "")
        }
        onClick>
        {label |> ReasonReact.string}
      </a>
    </div>,
};