import { Link } from 'react-router-dom'

export default function Home({ modules }) {
  return (
    <div className="page-home">
      <header className="hero">
        <h1>C 언어 학습</h1>
        <p>Java Spring 개발자를 위한 C 언어 웹 학습 프로젝트</p>
      </header>

      <section className="section">
        <h2>시작하기</h2>
        <p className="muted">
          C를 처음 보신다면 <Link to="/c-basics">C 기초 용어</Link>부터 읽어보세요.
          <code>#include</code>, <code>#define</code>, <code>#ifndef</code> 등이 한글으로 설명되어 있습니다.
        </p>
      </section>

      <section className="section">
        <h2>학습 순서</h2>
        <div className="module-grid">
          {modules.map(m => (
            <Link key={m.id} to={`/module/${m.id}`} className="module-card">
              <span className="module-num">{m.num}</span>
              <h3>{m.title}</h3>
              <p>{m.desc}</p>
            </Link>
          ))}
        </div>
      </section>

      <section className="section">
        <h2>브라우저에서 C 실행</h2>
        <p>
          <Link to="/playground">실행해보기</Link> 페이지에서 C 코드를 작성하고 브라우저에서 바로 실행할 수 있습니다.
          Piston API를 사용하며, 인터넷 연결이 필요합니다.
        </p>
      </section>
    </div>
  )
}
