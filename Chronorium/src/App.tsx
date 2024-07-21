import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from '/vite.svg';
import './App.css';
import LandingPage from './LandingPage.tsx' ; 
import SectionTwo from './SectionTwo.tsx' ; 
import SectionThree from './SectionThree.tsx' ; 
import NavBar from './NavBar.tsx' ; 




function App() {
  const scrollBar = document.getElementById('stickyHeader') ;
  return (
    <>
      <div className = "Overarching">
        <NavBar/>
        <LandingPage/>
        <SectionThree/> 
        <SectionTwo/> 
      </div>
    </>
  );
}

export default App;
