import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from '/vite.svg';
import './App.css';
import LandingPage from './LandingPage.tsx' ; 
import SectionTwo from './SectionTwo.tsx' ; 
import NavBar from './NavBar.tsx' ; 




function App() {


  return (
    <>
      <div className = "Overarching">
        <NavBar/>
        <LandingPage/>
        <SectionTwo/>
      </div>
    </>
  );
}

export default App;
