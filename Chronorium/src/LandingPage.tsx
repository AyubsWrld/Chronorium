

import React from 'react';
import Loops from './Loops'; // Adjust the path as needed
import './LandingPage.css'; // Import the CSS for the page
import companiesSvg from './assets/Grey.svg';

function LandingPage() {
  return (
    <div className="Container-Landing-Page">
      <Loops/> {/* Ensure this is the first child */}
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
