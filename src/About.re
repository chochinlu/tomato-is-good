module Link = {
  let component = ReasonReact.statelessComponent("Link");
  let make = (~title, ~href, _children) => {
    ...component,
    render: _self =>
      <div className="level-item">
        <i className="far fa-arrow-alt-circle-right" />
        <a href target="blank">
          <strong className="padding-left-icon padding-right-text">
            {title |> ReasonReact.string}
          </strong>
        </a>
      </div>,
  };
};

let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <div className="level">
      <div className="level-left">
        <p className="level-item">
          <strong> {"Tomato is Good." |> ReasonReact.string} </strong>
        </p>
      </div>
      <div className="level-right">
        <Link
          title="About Pomodoro Technique"
          href="https://francescocirillo.com/pages/pomodoro-technique"
        />
        <Link
          title={j|蕃茄工作法|j}
          href="https://zh.wikipedia.org/wiki/%E7%95%AA%E8%8C%84%E5%B7%A5%E4%BD%9C%E6%B3%95"
        />
      </div>
    </div>,
};