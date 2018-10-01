let component = ReasonReact.statelessComponent("ModeButton");

let make = (~label, ~onClick, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <a className="button is-fullwidth is-normal" onClick>
        {label |> ReasonReact.string}
      </a>
    </div>,
};