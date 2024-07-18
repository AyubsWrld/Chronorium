import React from 'react';
import './LandingPage.css';
import companiesSvg from './assets/Grey.svg';
import Loops from './Loops';

function LandingPage() {
  return (
    <div className="Container-Landing-Page">
      <div className="Loops-Container">
        <Loops />
      </div>
      <div className="Row-One"></div>
      <div className="Row-Two">
        <div className="OverarchingLanding">
          <div className="Text">
            <p className="HeaderOne">
              You're More Than <br /><span className="GradientText">Just a Slip of Paper.</span>
            </p>
            <p className="Subtext">
              Obtain tangible credentials that are as meaningful as the hard work <br /> you invest in achieving them.
            </p>
          </div>
          <div className="Buttons">
            <button className="JoinForFree">Join for free</button>
            <button className="Login">Log in</button>
          </div>
        </div>
      </div>
      <div className="Row-Three">
        <p className="Interviewers-Text">With Mentors who work at top companies.</p>
        <img src={companiesSvg} alt="Companies" className="Companies" />
      </div>
    </div>
  );
}

export default LandingPage;
