import React, { useEffect, useRef } from 'react';
import './SectionThree.css';
import lottie from 'lottie-web';
import GoodMorning from './assets/anims/Morning.json';

function SectionThree() {
  const goodMorningRef = useRef(null);
  const lottieAnimationRef = useRef(null);

  useEffect(() => {
    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            lottieAnimationRef.current = lottie.loadAnimation({
              container: goodMorningRef.current,
              renderer: 'svg',
              loop: false,
              autoplay: true,
              animationData: GoodMorning,
            });
          } else {
            if (lottieAnimationRef.current) {
              lottieAnimationRef.current.stop();
            }
          }
        });
      },
      { threshold: 0.5 } // Trigger when 50% of the element is visible
    );

    if (goodMorningRef.current) {
      observer.observe(goodMorningRef.current);
    }

    return () => {
      if (goodMorningRef.current) {
        observer.unobserve(goodMorningRef.current);
      }
      if (lottieAnimationRef.current) {
        lottieAnimationRef.current.destroy();
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
        <div className='ImageContainer' id='LeftMedia'>
          {/* Add any content if needed */}
        </div>
        <div className='ImageContainer' id='RightMedia'>
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
