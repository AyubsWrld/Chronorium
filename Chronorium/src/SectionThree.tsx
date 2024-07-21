import React, { useEffect, useRef } from 'react';
import './SectionThree.css';
import lottie from 'lottie-web';
import GoodMorning from './assets/anims/Morning.json';
import Credential from './assets/anims/Credential.json';

function SectionThree() {
  const goodMorningRef = useRef(null);
  const credentialRef = useRef(null);
  const lottieAnimationRef = useRef(null);
  const lottieAnimationCredentialRef = useRef(null);
  const leftMediaRef = useRef(null);
  const rightMediaRef = useRef(null);

  useEffect(() => {
    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            if (entry.target.id === 'LeftMedia') {
              entry.target.classList.add('shiftX-animation');
              lottieAnimationCredentialRef.current = lottie.loadAnimation({
                container: credentialRef.current,
                renderer: 'svg',
                loop: false,
                autoplay: true,
                animationData: Credential,
              });
            }
            if (entry.target.id === 'RightMedia') {
              entry.target.classList.add('shiftX-animation');
              lottieAnimationRef.current = lottie.loadAnimation({
                container: goodMorningRef.current,
                renderer: 'svg',
                loop: false,
                autoplay: true,
                animationData: GoodMorning,
              });
            }
          } else {
            if (entry.target.id === 'LeftMedia') {
              entry.target.classList.remove('shiftX-animation');
              void entry.target.offsetWidth; // Trigger reflow to restart the animation
              if (lottieAnimationCredentialRef.current) {
                lottieAnimationCredentialRef.current.destroy();
                lottieAnimationCredentialRef.current = null;
              }
            }
            if (entry.target.id === 'RightMedia') {
              entry.target.classList.remove('shiftX-animation');
              void entry.target.offsetWidth; // Trigger reflow to restart the animation
              if (lottieAnimationRef.current) {
                lottieAnimationRef.current.destroy();
                lottieAnimationRef.current = null;
              }
            }
          }
        });
      },
      { threshold: 0.2 } // Trigger when 20% of the element is visible
    );

    if (goodMorningRef.current) {
      observer.observe(goodMorningRef.current);
    }
    if (credentialRef.current) {
      observer.observe(credentialRef.current);
    }
    if (leftMediaRef.current) {
      observer.observe(leftMediaRef.current);
    }
    if (rightMediaRef.current) {
      observer.observe(rightMediaRef.current);
    }

    return () => {
      if (goodMorningRef.current) {
        observer.unobserve(goodMorningRef.current);
      }
      if (credentialRef.current) {
        observer.unobserve(credentialRef.current);
      }
      if (leftMediaRef.current) {
        observer.unobserve(leftMediaRef.current);
      }
      if (rightMediaRef.current) {
        observer.unobserve(rightMediaRef.current);
      }
      if (lottieAnimationRef.current) {
        lottieAnimationRef.current.destroy();
      }
      if (lottieAnimationCredentialRef.current) {
        lottieAnimationCredentialRef.current.destroy();
      }
    };
  }, []);

  return (
    <div className='Container-SectionThree'>
      <div className='RowOne'>
        <p className='ExpertLed'>
          Complete expert-led interviews.<br />
          <span className='HighlightText'>boost your hiring prospects</span>
        </p>
      </div>
      <div className='RowTwo'>
        <div className='ImageContainer' id='LeftMedia' ref={leftMediaRef}>
          <div className="LottieContainerThree" ref={credentialRef}></div>
        </div>
        <div className='ImageContainer' id='RightMedia' ref={rightMediaRef}>
          <div className="LottieContainerThree" ref={goodMorningRef}></div>
        </div>
      </div>
      <div className='RowThree'>
        <div>
          <p className='Subtext'>
            <span className='Bolded'>Schedule Your Interview.</span> Choose an expert from our network and<br />
            book a time that suits you. Prepare for a tailored interview designed<br />
            to assess your skills through practical, job-specific tasks.
          </p>
        </div>
        <div>
          <p className='Subtext'>
            <span className='Bolded'>Earn and Showcase Credentials.</span> receive credentials verified by<br />
            industry professionals. Display these credentials on your profile to<br />
            demonstrate your expertise and improve your hiring prospects.
          </p>
        </div>
      </div>
    </div>
  );
}

export default SectionThree;
