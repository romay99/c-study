import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter'
import { oneDark, holiTheme, coldarkDark, nightOwl, prism, materialOceanic, a11yDark,dracula} from 'react-syntax-highlighter/dist/esm/styles/prism'
import './CodeBlock.css'

export default function CodeBlock({ code, language = 'c', filename }) {
  return (
    <div className="code-block">
      {filename && <div className="code-filename">{filename}</div>}
      <SyntaxHighlighter
        language={language}
        style={dracula}
        showLineNumbers
        customStyle={{ margin: 0, borderRadius: '0 0 8px 8px' }}
        codeTagProps={{ style: { fontFamily: 'var(--font-mono)', fontSize: '0.9rem' } }}
      >
        {code}
      </SyntaxHighlighter>
    </div>
  )
}
