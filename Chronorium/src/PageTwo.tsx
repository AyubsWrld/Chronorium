import { useState } from 'react';
import './PageTwo.css';
import NavBar from './NavBar.tsx';
import companiesSvg from './assets/Grey.svg';


function PageTwo() {
 return(
  <>
      <div className = "Page-Two" >
        <p className = "Header">
          From Capability to Career.
        </p>
        <div className = "Cards">
          <div className = "ItemOne">
            <div className = "AnimationOne">
            </div>
            <p className = "CardTitle">
              Header One
            </p>
            <p className = "CardSubtext">
              Lorem Ipsum Generator
              Generate Lorem Ipsum placeholder text. Select the number of characters, <br /> words, sentences or paragraphs, and hit generate!
              freestar
              GENERATED LOREM IPSUM
            </p>
          </div>
        </div>
      </div>
  </>
 ) ;
}

export default PageTwo; 
