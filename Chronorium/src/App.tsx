import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from '/vite.svg';
import './App.css';
import LandingPage from './LandingPage.tsx' ; 
import PageTwo from './PageTwo.tsx' ; 
import SectionTwo from './SectionTwo.tsx' ; 
import SectionThree from './SectionThree.tsx' ; 



function App() {


  return (
    <>
      <div className = "Overarching">
        <LandingPage/>
        {/* <SectionTwo/> */}
        {/* <SectionThree/> */}
        {/* <PageTwo/> */}
      </div>
    </>
  );
}

export default App;
