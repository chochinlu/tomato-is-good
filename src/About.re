let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="level">
      <div className="level-left">
        <p className="level-item">
          <strong>
            ("Tomato is Good." |> ReasonReact.string)
          </strong>
        </p>
      </div>
      <div className="level-right">
        <i className="far fa-arrow-alt-circle-right" />
        <strong className="padding-left-icon">
          <a className="level-item" href="https://francescocirillo.com/pages/pomodoro-technique" target="blank">
            ("About Pomodoro Technique" |> ReasonReact.string)
          </a>
        </strong>
      </div>
    </div>
};
