let component = ReasonReact.statelessComponent("ModeButton");

let make = (~label, ~onClick, ~selected, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <a
        className={
          "button is-rounded is-fullwidth "
          ++ (selected ? "is-info" : "is-primary is-outlined")
        }
        onClick>
        {label |> ReasonReact.string}
      </a>
    </div>,
};