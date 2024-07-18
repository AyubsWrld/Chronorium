import reactLogo from './assets/react.svg';
import viteLogo from '/vite.svg';
import './SectionTwo.css';

function SectionTwo() {
  return (
    <div className="Container-Section-Two">

      <div className="ArtworkOne">

        <div className="Image">
          {/* Add your image here */}
        </div>

        <div className="Text-Section-Two">
          <p className="Header-Section-Two">
            From Capability <br />to Careers.
          </p>
          <p className="Subtext-Section-Two">
            Discover a new era of tech<br />credentialing where your true<br />capabilities are recognized and <br />valued.
          </p>
        </div>

      </div>

      <div className="ArtworkTwo">

        <div className="Text-Section-Two">
          <p className="Header-Section-Two">
            Fostering <br />Continuous <br />Growth
          </p>
          <p className="Subtext-Section-Two">
            Connect with industry leaders, <br />participate in advanced training, <br />and continuously enhance your <br />skills.
          </p>
        </div>
        <div className="Image">
          {/* Add your image here */}
        </div>

      </div>
    </div>
  );
}

export default SectionTwo;
