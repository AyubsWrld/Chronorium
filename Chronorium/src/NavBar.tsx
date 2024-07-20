import React from "react";
import Logo from "./assets/white.png";
import "./NavBar.css"; // Import your CSS file

const NavBar = () => {
  return (
    <header className="sticky-header" id = 'stickyHeader'>
      <div className="header-content">
        <div className="logo-container">
          <img src= {Logo} alt="Logo" className="logo-image" />
          <h1 className="logo-text">Certy</h1>
        </div>
        <nav className="header-menu">
          <ul>
            <li><a href="#services">Pricing</a></li>
            <li><a href="#contact">Log in</a></li>
          </ul>
        </nav>
      </div>
    </header>
  );
};

export default NavBar;
