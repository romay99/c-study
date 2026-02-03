import { useEffect, useState } from 'react'
import { useParams, Link } from 'react-router-dom'
import CodeBlock from '../components/CodeBlock'
import CodeRunner from '../components/CodeRunner'
import { codePaths, runnableExamples } from '../content/codeData'

const moduleExamples = {
  '01_basics': [
    { key: 'basics_variables', label: '변수와 타입' },
    { key: 'basics_operators', label: '연산자' },
    { key: 'basics_control', label: '제어문' },
    { key: 'basics_array', label: '배열' },
    { key: 'basics_string', label: '문자열' },
  ],
  '02_pointers': [
    { key: 'pointer_basic', label: '포인터 기본' },
    { key: 'pointer_swap', label: 'Call by reference (swap)' },
  ],
  '03_struct': [
    { key: 'struct_basic', label: '구조체 기본' },
  ],
  '04_memory': [
    { key: 'memory_malloc', label: 'malloc/free' },
  ],
}

export default function Module({ modules }) {
  const { moduleId } = useParams()
  const module = modules?.find(m => m.id === moduleId)
  const [headerCode, setHeaderCode] = useState('')
  const [sourceCode, setSourceCode] = useState('')
  const [loading, setLoading] = useState(true)

  const paths2 = codePaths[moduleId]

  useEffect(() => {
    if (!moduleId || !paths2) return
    setLoading(true)
    Promise.all([
      fetch(paths2.header).then(r => r.text()),
      fetch(paths2.source).then(r => r.text()),
    ])
      .then(([h, s]) => {
        setHeaderCode(h)
        setSourceCode(s)
      })
      .catch(() => {
        setHeaderCode('// 파일을 불러올 수 없습니다.')
        setSourceCode('// 파일을 불러올 수 없습니다.')
      })
      .finally(() => setLoading(false))
  }, [moduleId, paths2])

  const examples = moduleExamples[moduleId] || []
  const [selectedExample, setSelectedExample] = useState(examples[0]?.key)

  if (!module) {
    return (
      <div className="page-module">
        <p>모듈을 찾을 수 없습니다. <Link to="/">홈으로</Link></p>
      </div>
    )
  }

  return (
    <div className="page-module">
      <header className="page-header">
        <h1>[{module.num}단계] {module.title}</h1>
        <p>{module.desc}</p>
      </header>

      <section className="section">
        <h2>소스 코드</h2>
        {loading ? (
          <p>로딩 중...</p>
        ) : (
          <>
            <CodeBlock code={headerCode} filename={`include/${moduleId?.replace(/^\d+_/, '')}.h`} />
            <CodeBlock code={sourceCode} filename={`${moduleId}/${moduleId?.replace(/^\d+_/, '')}.c`} />
          </>
        )}
      </section>

      {examples.length > 0 && (
        <section className="section">
          <h2>실행해보기</h2>
          <p className="muted">아래 예제를 수정하고 실행 버튼을 눌러보세요. (Piston API 사용, 인터넷 필요)</p>
          <div className="example-tabs">
            {examples.map(ex => (
              <button
                key={ex.key}
                className={selectedExample === ex.key ? 'active' : ''}
                onClick={() => setSelectedExample(ex.key)}
              >
                {ex.label}
              </button>
            ))}
          </div>
          {selectedExample && runnableExamples[selectedExample] && (
            <CodeRunner defaultCode={runnableExamples[selectedExample]} label="실행" />
          )}
        </section>
      )}
    </div>
  )
}
