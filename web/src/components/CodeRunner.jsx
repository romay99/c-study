import { useState } from 'react'
import CodeBlock from './CodeBlock'
import './CodeRunner.css'

const PISTON_URL = 'https://emkc.org/api/v2/piston/execute'

export default function CodeRunner({ defaultCode, label = '실행' }) {
  const [code, setCode] = useState(defaultCode)
  const [output, setOutput] = useState('')
  const [loading, setLoading] = useState(false)
  const [error, setError] = useState('')

  async function run() {
    setLoading(true)
    setOutput('')
    setError('')
    try {
      const res = await fetch(PISTON_URL, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          language: 'c',
          version: '*',
          files: [{ content: code }],
        }),
      })
      const data = await res.json()
      if (data.message) {
        setError(data.message)
      } else if (data.run) {
        const out = data.run.stdout || ''
        const err = data.run.stderr || ''
        setOutput(out + (err ? '\n[stderr]\n' + err : ''))
      }
    } catch (e) {
      setError('실행 실패: ' + e.message + '. (인터넷 연결 확인)')
    } finally {
      setLoading(false)
    }
  }

  return (
    <div className="code-runner">
      <div className="code-runner-editor">
        <div className="code-runner-toolbar">
          <span className="code-runner-label">C 코드 (수정 가능)</span>
          <button onClick={run} disabled={loading} className="run-btn">
            {loading ? '실행 중...' : label}
          </button>
        </div>
        <textarea
          value={code}
          onChange={e => setCode(e.target.value)}
          spellCheck={false}
          className="code-runner-textarea"
        />
      </div>
      {(output || error) && (
        <div className={`code-runner-output ${error ? 'error' : ''}`}>
          <div className="output-header">{error ? '오류' : '실행 결과'}</div>
          <pre>{error || output || '(출력 없음)'}</pre>
        </div>
      )}
    </div>
  )
}
