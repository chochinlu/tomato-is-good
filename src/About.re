module Link = {
  let component = ReasonReact.statelessComponent("Link");
  let make = (~title, ~href, _children) => {
    ...component,
    render: _self =>
      <>
        <i className="far fa-arrow-alt-circle-right" />
        <strong className="padding-left-icon padding-right-text">
          <a className="level-item" href target="blank">
            {title |> ReasonReact.string}
          </a>
        </strong>
      </>,
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
          title={j|蕃茄工作法wiki|j}
          href="https://zh.wikipedia.org/wiki/%E7%95%AA%E8%8C%84%E5%B7%A5%E4%BD%9C%E6%B3%95"
        />
      </div>
    </div>,
};