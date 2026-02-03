import { Routes, Route, Link, useLocation } from 'react-router-dom'
import Home from './pages/Home'
import Module from './pages/Module'
import CBasics from './pages/CBasics'
import Playground from './pages/Playground'
import './App.css'

const modules = [
  { id: '01_basics', num: 1, title: '기본 문법', desc: '변수, 연산자, 제어문, 배열, 문자열' },
  { id: '02_pointers', num: 2, title: '포인터', desc: 'C의 핵심! &, *, 주소' },
  { id: '03_struct', num: 3, title: '구조체', desc: 'Java 클래스와 유사' },
  { id: '04_memory', num: 4, title: '메모리', desc: 'malloc, free' },
]

function Nav() {
  const loc = useLocation()
  return (
    <nav className="nav">
      <Link to="/" className="nav-logo">C 학습</Link>
      <div className="nav-links">
        <Link to="/" className={loc.pathname === '/' ? 'active' : ''}>홈</Link>
        <Link to="/c-basics" className={loc.pathname === '/c-basics' ? 'active' : ''}>C 기초</Link>
        <Link to="/playground" className={loc.pathname === '/playground' ? 'active' : ''}>실행해보기</Link>
        {modules.map(m => (
          <Link
            key={m.id}
            to={`/module/${m.id}`}
            className={loc.pathname === `/module/${m.id}` ? 'active' : ''}
          >
            {m.num}. {m.title}
          </Link>
        ))}
      </div>
    </nav>
  )
}

function App() {
  return (
    <>
      <Nav />
      <main className="main">
        <Routes>
          <Route path="/" element={<Home modules={modules} />} />
          <Route path="/c-basics" element={<CBasics />} />
          <Route path="/playground" element={<Playground />} />
          <Route path="/module/:moduleId" element={<Module modules={modules} />} />
        </Routes>
      </main>
    </>
  )
}

export default App
