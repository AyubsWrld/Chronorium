import React, { useEffect, useRef } from 'react';
import lottie from 'lottie-web';
import capabilitiesIcon from './assets/Icons/Capabilities.png';
import star from './assets/Icons/Star.png';
import checkmark from './assets/Icons/Checkmark.png';
import animationData from './assets/anims/Stars.json';
import animationDataTwo from './assets/anims/Resumes.json';
import animationDataThree from './assets/anims/Terminal.json';
import './SectionTwo.css';

function SectionTwo() {
  const lottieRef = useRef(null);
  const lottieRefTwo = useRef(null);
  const lottieRefThree = useRef(null);

  useEffect(() => {
    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            lottie.loadAnimation({
              container: lottieRef.current,
              renderer: 'svg',
              loop: false,
              autoplay: true,
              animationData: animationData,
            });
            lottie.loadAnimation({
              container: lottieRefTwo.current,
              renderer: 'svg',
              loop: false,
              autoplay: true,
              animationData: animationDataTwo,
            });
            lottie.loadAnimation({
              container: lottieRefThree.current,
              renderer: 'svg',
              loop: false,
              autoplay: true,
              animationData: animationDataThree,
            });
          } else {
            lottie.stop();
          }
        });
      },
      { threshold: 0.5 } // Trigger when 50% of the element is visible
    );

    if (lottieRef.current) observer.observe(lottieRef.current);
    if (lottieRefTwo.current) observer.observe(lottieRefTwo.current);
    if (lottieRefThree.current) observer.observe(lottieRefThree.current);

    return () => {
      if (lottieRef.current) observer.unobserve(lottieRef.current);
      if (lottieRefTwo.current) observer.unobserve(lottieRefTwo.current);
      if (lottieRefThree.current) observer.unobserve(lottieRefThree.current);
    };
  }, []);

  return (
    <div className="Container-Section-Two">
      <div className="RowOne">
        <div className="ArtworkOne">
          <div className="Image">
            <div className="LottieContainer" ref={lottieRef}></div>
            <img src={capabilitiesIcon} alt="capabilities" className="Capabilities" />
            <p className="Careers">
              From Capabilities to <span className="Span">Careers.</span>
            </p>
            <p className="Subtext">
              Have your true capabilities recognized and valued.
            </p>
          </div>
        </div>
        <div className="ArtworkTwo">
          <div className="Image">
            <div className="LottieContainerTwo" ref={lottieRefTwo}></div>
            <img src={star} alt="capabilities" className="Capabilities" />
            <p className="Careers">
              Gain the Visibility You <span className="Span">Deserve.</span>
            </p>
            <p className="Subtext">
              Connect with industry leaders and achieve<br />the visibility you deserve.
            </p>
          </div>
        </div>
      </div>
      <div className="RowTwo">
        <div className="ArtworkThree">
          <div className="ImageThree">
            <div className="LottieContainerThree" ref={lottieRefThree}></div>
            <img src={checkmark} alt="capabilities" className="Capabilities" />
            <p className="Careers">
              Add <span className="Span">Credibility</span> to Your Craft.
            </p>
            <p className="Subtext">
              Build your reputation and showcase your mastery<br />with confidence.
            </p>
          </div>
        </div>
      </div>
    </div>
  );
}

export default SectionTwo;
